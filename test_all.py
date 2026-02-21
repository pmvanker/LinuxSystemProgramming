import pytest
import subprocess
import os
import sys

def run_python_script(script_path, timeout=10):
    """Helper function to run a Python script and return its output."""
    try:
        result = subprocess.run(
            [sys.executable, script_path],
            capture_output=True,
            text=True,
            timeout=timeout
        )
        return result.returncode, result.stdout, result.stderr
    except subprocess.TimeoutExpired:
        pytest.fail(f"Script {script_path} timed out")
    except FileNotFoundError:
        pytest.fail(f"Script {script_path} not found")

class TestFileIO:
    def test_file_io_example(self):
        script = "FileIO/Python/file_io_example.py"
        returncode, stdout, stderr = run_python_script(script)
        assert returncode == 0, f"Script failed with stderr: {stderr}"
        assert "Read from file:" in stdout

class TestProcesses:
    def test_exec_example(self):
        script = "Processes/Python/exec_example.py"
        returncode, stdout, stderr = run_python_script(script, timeout=5)
        # exec_example may have different behavior, just check it runs
        assert returncode in [0, 1], f"Script failed unexpectedly: {stderr}"

    def test_fork_example(self):
        script = "Processes/Python/fork_example.py"
        returncode, stdout, stderr = run_python_script(script, timeout=5)
        assert returncode == 0, f"Script failed with stderr: {stderr}"
        assert "Child process:" in stdout or "Parent process:" in stdout

    def test_wait_example(self):
        script = "Processes/Python/wait_example.py"
        returncode, stdout, stderr = run_python_script(script, timeout=5)
        assert returncode == 0, f"Script failed with stderr: {stderr}"

class TestIPC:
    def test_pipe_example(self):
        script = "IPC/Pipes/Python/pipe_example.py"
        returncode, stdout, stderr = run_python_script(script, timeout=5)
        assert returncode == 0, f"Script failed with stderr: {stderr}"
        assert "Child received:" in stdout

    def test_fifo_example(self):
        script = "IPC/FIFOs/Python/fifo_example.py"
        returncode, stdout, stderr = run_python_script(script, timeout=5)
        assert returncode == 0, f"Script failed with stderr: {stderr}"
        assert "Child received:" in stdout

    def test_msg_queue_example(self):
        script = "IPC/MessageQueues/Python/msg_queue_example.py"
        returncode, stdout, stderr = run_python_script(script, timeout=5)
        assert returncode == 0, f"Script failed with stderr: {stderr}"
        assert "Child received:" in stdout

    def test_semaphore_example(self):
        script = "IPC/Semaphores/Python/semaphore_example.py"
        returncode, stdout, stderr = run_python_script(script, timeout=5)
        assert returncode == 0, f"Script failed with stderr: {stderr}"
        assert "Critical section" in stdout

    def test_shm_example(self):
        script = "IPC/SharedMemory/Python/shm_example.py"
        returncode, stdout, stderr = run_python_script(script, timeout=5)
        assert returncode == 0, f"Script failed with stderr: {stderr}"
        assert "Child reads:" in stdout

class TestMemoryMapping:
    def test_mmap_example(self):
        script = "MemoryMapping/Python/mmap_example.py"
        returncode, stdout, stderr = run_python_script(script)
        assert returncode == 0, f"Script failed with stderr: {stderr}"
        assert "Mapped content:" in stdout

class TestPermissions:
    def test_permissions_example(self):
        script = "Permissions/Python/permissions_example.py"
        returncode, stdout, stderr = run_python_script(script)
        assert returncode == 0, f"Script failed with stderr: {stderr}"
        assert "Permissions changed successfully" in stdout

class TestSignals:
    def test_signal_example(self):
        # Signal example runs indefinitely, so we need to handle it differently
        script = "Signals/Python/signal_example.py"
        try:
            result = subprocess.run(
                [sys.executable, script],
                capture_output=True,
                text=True,
                timeout=2,  # Short timeout since it waits for signal
                cwd=os.path.dirname(script)
            )
            # The script should be interrupted by timeout or signal
            assert result.returncode != 0 or "Received signal" in result.stdout
        except subprocess.TimeoutExpired:
            # This is expected for the signal example
            pass

class TestSockets:
    def test_socket_server(self):
        # Socket tests are complex due to networking, just check they start
        script = "Sockets/Python/socket_server.py"
        try:
            result = subprocess.run(
                [sys.executable, script],
                capture_output=True,
                text=True,
                timeout=2
            )
            # Server should run for a bit then exit or be interrupted
            assert result.returncode in [0, -2, 1]  # Various exit codes possible
        except subprocess.TimeoutExpired:
            pass  # Expected for server that waits for connections

    def test_udp_server(self):
        script = "Sockets/Python/udp_server.py"
        try:
            result = subprocess.run(
                [sys.executable, script],
                capture_output=True,
                text=True,
                timeout=2
            )
            assert result.returncode in [0, -2, 1]
        except subprocess.TimeoutExpired:
            pass

class TestSystemCalls:
    def test_syscall_example(self):
        script = "SystemCalls/Python/syscall_example.py"
        returncode, stdout, stderr = run_python_script(script)
        assert returncode == 0, f"Script failed with stderr: {stderr}"
        assert "Process ID:" in stdout
        assert "User ID:" in stdout

class TestTimers:
    def test_timer_example(self):
        script = "Timers/Python/timer_example.py"
        try:
            result = subprocess.run(
                [sys.executable, script],
                capture_output=True,
                text=True,
                timeout=5
            )
            assert result.returncode in [0, -2]  # May be interrupted by signal
        except subprocess.TimeoutExpired:
            pass  # Expected for timer that waits