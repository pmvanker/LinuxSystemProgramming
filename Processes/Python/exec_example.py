import os
import sys

pid = os.fork()
if pid < 0:
    print("fork failed", file=sys.stderr)
    sys.exit(1)
elif pid == 0:
    os.execvp("echo", ["echo", "Hello from exec"])
else:
    os.wait()
    print("Parent: exec finished")