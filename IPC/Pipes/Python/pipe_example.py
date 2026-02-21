import os

r, w = os.pipe()

pid = os.fork()

if pid == 0:  # Child
    os.close(w)
    msg = os.read(r, 100)
    print("Child received:", msg.decode())
    os.close(r)
else:  # Parent
    os.close(r)
    msg = b"Hello from parent"
    os.write(w, msg)
    os.close(w)
    os.wait()