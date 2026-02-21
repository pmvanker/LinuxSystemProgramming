from multiprocessing import Process, Value
import time

def child(shared_str):
    print("Child reads:", shared_str.value.decode())

if __name__ == '__main__':
    shared_str = Value('c', b'Hello from parent')
    p = Process(target=child, args=(shared_str,))
    p.start()
    time.sleep(1)
    p.join()