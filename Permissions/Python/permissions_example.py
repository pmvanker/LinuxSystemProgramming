import os

# Create a file
with open('test.txt', 'w') as f:
    f.write('Test content\n')

# Change permissions to 0644
os.chmod('test.txt', 0o644)

print("Permissions changed successfully")

# Remove the file
os.remove('test.txt')