import os
import sys

pid = os.fork()
if pid < 0:
    print("fork failed", file=sys.stderr)
    sys.exit(1)
elif pid == 0:
    print(f"Child process: PID = {os.getpid()}, Parent PID = {os.getppid()}")
else:
    print(f"Parent process: PID = {os.getpid()}, Child PID = {pid}")
    os.wait()
    print("Child finished")