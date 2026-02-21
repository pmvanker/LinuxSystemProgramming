# Use 'with' statement for file handling - automatically closes file
# open() with 'w' mode: write mode, creates file if not exists, truncates if exists
with open('example.txt', 'w') as f:
    # write() method: writes string to file
    f.write('Hello, World!\n')

# open() with 'r' mode: read mode, file must exist
with open('example.txt', 'r') as f:
    # read() method: reads entire file content as string
    content = f.read()
    print('Read from file:', content.strip())