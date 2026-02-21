import os

fifo = '/tmp/myfifo'
os.mkfifo(fifo, 0o666)

pid = os.fork()

if pid == 0:  # Child
    fd = os.open(fifo, os.O_RDONLY)
    msg = os.read(fd, 100)
    print("Child received:", msg.decode())
    os.close(fd)
    os.unlink(fifo)
else:  # Parent
    fd = os.open(fifo, os.O_WRONLY)
    msg = b"Hello from parent"
    os.write(fd, msg)
    os.close(fd)
    os.wait()