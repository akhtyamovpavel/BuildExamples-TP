import json
import sys


if __name__ == '__main__':
  in_file = sys.argv[1]
  output_file = sys.argv[2]
  doc = None
  with open(in_file, 'r') as fp:
      doc = json.load(fp)
  print(doc)
  output_document = json.dumps(doc).replace(
    '[', '{'
  ).replace(
     ']', '}'
  )
  with open(output_file, 'w') as fp:
    fp.write(f'int arr[] = {output_document};')
  sys.stdout.write(' '.join(sys.argv))
