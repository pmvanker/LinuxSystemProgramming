import signal
import time

def timer_handler(signum, frame):
    print("Timer expired")

signal.signal(signal.SIGALRM, timer_handler)
signal.alarm(2)

time.sleep(3)  # Wait