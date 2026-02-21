from multiprocessing import Process, Semaphore

def child(sem):
    sem.acquire()
    print("Child: Critical section")
    sem.release()

if __name__ == '__main__':
    sem = Semaphore(1)
    p = Process(target=child, args=(sem,))
    p.start()
    sem.acquire()
    print("Parent: Critical section")
    sem.release()
    p.join()