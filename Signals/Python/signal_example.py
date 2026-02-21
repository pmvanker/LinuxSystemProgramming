import signal
import time

def signal_handler(sig, frame):
    print(f'Received signal {sig}')

signal.signal(signal.SIGINT, signal_handler)

print("Press Ctrl+C to send SIGINT")
while True:
    time.sleep(1)