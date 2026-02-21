import mmap
import os

with open('example.txt', 'w+b') as f:
    f.write(b'Hello, World!')

with open('example.txt', 'r+b') as f:
    mm = mmap.mmap(f.fileno(), 0)
    print("Mapped content:", mm.read().decode())
    mm.close()

os.unlink('example.txt')