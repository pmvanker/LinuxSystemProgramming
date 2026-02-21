import os
import sys

pid = os.fork()
if pid < 0:
    print("fork failed", file=sys.stderr)
    sys.exit(1)
elif pid == 0:
    os._exit(42)
else:
    pid_wait, status = os.wait()
    print(f"Child {pid_wait} exited with status {os.WEXITSTATUS(status)}")