with open('hex_values32.txt', 'w') as file:
    # Iterate over all values from 0 to 2^64 - 1
    for i in range(2**16):
        # Convert the integer to hexadecimal with leading zeroes
        hex_value = f'{i:016b}'  # 16 characters for 64-bit hexadecimal values
        # Write the value to the file followed by a newline
        file.write(hex_value + '\n')
