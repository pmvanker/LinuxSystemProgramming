from multiprocessing import Process, Queue

def child(q):
    msg = q.get()
    print("Child received:", msg)

if __name__ == '__main__':
    q = Queue()
    p = Process(target=child, args=(q,))
    p.start()
    q.put("Hello from parent")
    p.join()