#!/usr/bin/env python
import os
import zipfile


def zip_directory(path, zip_file):
    for root, dirs, files in os.walk(path):
        for file in files:
            file_path = os.path.join(root, file)
            zip_file.write(
                file_path,
                os.path.relpath(
                    file_path,
                    os.path.join(path, '..')))


if __name__ == '__main__':
    output_file = zipfile.ZipFile('output/sources.zip', 'w', zipfile.ZIP_DEFLATED)
    zip_directory('src/', output_file)
    output_file.close()
