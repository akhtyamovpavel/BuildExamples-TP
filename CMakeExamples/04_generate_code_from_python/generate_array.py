import json
import sys

if __name__ == '__main__':
  output_file = sys.argv[2]
  with open(output_file, 'w') as fp:
    fp.write("int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};")
  sys.stdout.write(' '.join(sys.argv))
