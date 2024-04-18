"""
H2UMLconverter.py

This script converts C++ header files (.h) into UML class diagrams and outputs the result to a text file.
The converter doesn't handle private visibility specifiers

Usage:
    python H2UMLconverter.py <folder_path>

Author:
    David Gianadda
    This script was generated with the assistance of an AI language model

Description:
    This script recursively processes all .h files within the specified folder_path.
    It extracts class names, attributes, and methods from the header files and generates
    UML class diagrams in text format, organized by class.

    Classes:
        - Each class is represented by its name followed by its attributes and methods.
        - Attributes are listed with a '-' symbol and include their data type.
        - Methods are listed with a '+' symbol and include their return type and parameters.

    Example Usage:
        python H2UMLconverter.py "./folder_containing_header_files"

Date:
    18.04.2024
"""

import os
import sys
import re

class UMLClass:
    def __init__(self, name):
        self.name = name
        self.attributes = []
        self.methods = []
        self.constructor = None

    def add_attribute(self, attribute):
        self.attributes.append(attribute)

    def add_method(self, method):
        self.methods.append(method)

    def __str__(self):
        lines = [f"{self.name}\n"]
        for attr in self.attributes:
            visibility_symbol = "+" if attr.visibility == "public" else "-"
            lines.append(f"{visibility_symbol} {attr}\n")
        
        lines.append("_____________________\n")
        
        for method in self.methods:
            visibility_symbol = "+" if method.visibility == "public" else "-"
            lines.append(f"{visibility_symbol} {method}\n")
        return ''.join(lines)


class Attribute:
    def __init__(self, name, data_type, visibility):
        self.name = name
        self.data_type = data_type
        self.visibility = visibility

    def __str__(self):
        return f"{self.name}: {self.data_type}"


class Method:
    def __init__(self, name, return_type, visibility, is_constructor = False):
        self.name = name
        self.return_type = return_type
        self.visibility = visibility
        self.is_constructor = is_constructor

    def __str__(self):
        if self.is_constructor:
            return f"{self.name}()"
        else:
            return f"{self.name}(): {self.return_type}"



def parse_header_file(file_path):
    # Define regular expression to match class name
    class_regex = re.compile(r'class\s+(\w+)\s*:?(\s*{)?')

    # Define regular expressions to match attribute and method definitions
    attribute_regex = re.compile(r'(\w+)\s+(\w+)\s*;')
    method_regex = re.compile(r'(\w+)\s+(\w+)\s*\([^)]*\)\s*;')

    # Dictionary to store UMLClass objects
    classes = {}

    with open(file_path, 'r') as file:
        current_class = None
        visibility = "private"  # Default visibility
        for line in file:
            # Check if the line contains a class definition
            class_match = class_regex.search(line)
            if class_match:
                current_class = class_match.group(1)
                classes[current_class] = UMLClass(current_class)
            elif current_class:
                # Check if the line defines an attribute
                attribute_match = attribute_regex.search(line)
                if attribute_match:
                    attr_type, attr_name = attribute_match.group(1), attribute_match.group(2)
                    classes[current_class].add_attribute(Attribute(attr_name, attr_type, visibility))
                else:
                    # Check if the line defines a method
                    method_match = method_regex.search(line)
                    if method_match:
                        method_name, method_return_type = method_match.group(2), method_match.group(1)
                        classes[current_class].add_method(Method(method_name, method_return_type, visibility))
                    # Check if the line defines a constructor
                    elif f"{current_class}(" in line:
                        constructor_name = current_class
                        classes[current_class].add_method(Method(constructor_name, "", visibility, is_constructor=True))
                    # Update visibility if a visibility specifier is found
                    elif "public:" in line:
                        visibility = "public"
                    elif "private:" in line:
                        visibility = "private"
                    elif not (line.strip() == "" or line.strip() == "#endif" or line.strip() == "};" or line.strip() == "{"):
                        print(f"/!\ Unmatched line: {line.strip()}")

    return classes







def process_folder(folder_path):
    print(f"Processing folder: {folder_path}")

    # Get all .h files in the specified folder
    header_files = [f for f in os.listdir(folder_path) if f.endswith('.h')]
    print(f"Found {len(header_files)} .h files")

    # Process each .h file
    for file_name in header_files:
        file_path = os.path.join(folder_path, file_name)
        print(f"Processing file: {file_path}")
        classes = parse_header_file(file_path)
        for class_name, uml_class in classes.items():
            write_class_to_output(uml_class, f"Content of {class_name} in {file_name}")


def write_class_to_output(uml_class, section_header):
    with open("H2UML_output.txt", 'a') as output_file:
        output_file.write(f"{section_header}:\n")
        output_file.write(str(uml_class) + "\n\n")


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script_name.py <folder_path>")
        sys.exit(1)

    folder_path = sys.argv[1]

    # Delete existing H2UML_output.txt file if it exists
    if os.path.exists("H2UML_output.txt"):
        os.remove("H2UML_output.txt")

    process_folder(folder_path)
    print("Content written to H2UML_output.txt, Remember to double check results")
