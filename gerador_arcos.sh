input_file=$1

> arcos_gerados.txt

# Loop through each line in the file
while IFS= read -r line
do
  # Run the program with the content of the line as an argument
  ./AT "$line" >> arcos_gerados.txt
done < "$input_file"
