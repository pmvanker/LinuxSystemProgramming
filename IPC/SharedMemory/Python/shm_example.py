import mmap
import os
import time

def child():
    # Open the shared memory file
    fd = os.open('/tmp/shared_memory', os.O_RDONLY)
    # Memory map the file
    mm = mmap.mmap(fd, 0, mmap.MAP_SHARED, mmap.PROT_READ)
    print("Child reads:", mm.read().decode().strip())
    mm.close()
    os.close(fd)

if __name__ == '__main__':
    # Create a shared memory file
    with open('/tmp/shared_memory', 'w+b') as f:
        f.write(b'Hello from parent')

    # Fork the process
    pid = os.fork()
    if pid == 0:
        # Child process
        child()
    else:
        # Parent process
        time.sleep(1)  # Wait for child to read
        os.waitpid(pid, 0)  # Wait for child to finish