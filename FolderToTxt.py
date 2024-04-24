import os
import sys

def merge_files(folder_path, output_file):
    with open(output_file, 'w') as output:
        for filename in os.listdir(folder_path):
            file_path = os.path.join(folder_path, filename)
            if os.path.isfile(file_path):
                with open(file_path, 'r') as file:
                    output.write(f"Contents of {filename}:\n")
                    output.write(file.read())
                    output.write('\n\n')

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script_name.py <folder_path>")
        sys.exit(1)

    folder_path = sys.argv[1]

    output_file = "FolderToTxt_output.txt"

    merge_files(folder_path, output_file)

    print(f"Contents of all files in {folder_path} merged into {output_file}")
