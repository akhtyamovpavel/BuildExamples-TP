import json
import sys


if __name__ == '__main__':
  in_file = sys.argv[1]
  output_file = sys.argv[2]
  doc = None
  with open(in_file, 'r') as fp:
      doc = json.load(fp)
  print(doc)
  with open(output_file, 'w') as fp:
    fp.write('int arr[] = {{ {} }};'.format(', '.join([str(element) for element in doc])))
  sys.stdout.write(' '.join(sys.argv))
