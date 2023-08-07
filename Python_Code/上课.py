from threading import Thread, Semaphore
import time

readers = 0
mutex = Semaphore(1)
roomEmpty = Semaphore(1)

def writer():
    global readers
    mutex.acquire()
    while readers > 0:
        mutex.release()
        roomEmpty.acquire()
        mutex.acquire()
    print('writer start writing...')
    time.sleep(2) # 模拟写入操作
    print('writer end writing...')
    mutex.release()
    roomEmpty.release()

def reader():
    global readers
    mutex.acquire()
    readers += 1
    if readers == 1:
        roomEmpty.acquire()
    mutex.release()
    print('reader start reading...')
    time.sleep(1) # 模拟读取操作
    print('reader end reading...')
    mutex.acquire()
    readers -= 1
    if readers == 0:
        roomEmpty.release()
    mutex.release()

if __name__ == '__main__':
    threads = []
    for i in range(5):
        threads.append(Thread(target=reader))
        threads.append(Thread(target=writer))
    for t in threads:
        t.start()


