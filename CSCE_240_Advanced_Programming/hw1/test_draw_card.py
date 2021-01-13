#!/usr/bin/env python3
"""Module documentation goes here
"""

import subprocess
import sys

class QuickTest:
    """Class documentation goes here
    """
    def __init__(self, test_count):
        self.__APP = "./draw_card"
        self.__test_count = str(test_count)
        self.__percent_low = float(self.__test_count) * 0.5/52.0
        self.__percent_high = float(self.__test_count) * 1.5/52.0
        self.results = dict()

        self.__TestDrawCards()


    def __TestDrawCards(self):
        """Method documentation goes here
        """
        returncode, out = self.__Exec(self.__APP, self.__test_count.encode())

        if 0 != returncode:
            print("\t ERROR: Return value from student app: {}."
                    .format(returncode), file=sys.stderr)
            sys.exit(returncode)

        if None == out:
            print("\t ERROR: No output from student app.", file=sys.stderr) 
            sys.exit(2)

        cards = out.split()
        for card in cards:
            suit = card[len(card) - 1]
            face = card[0 : len(card) - 1]

            if len(face) == 1:
                face = '0' + face if face.isdigit() else ' ' + face

            if suit not in self.results:              
              self.results[suit] = {face : 1}
            elif face not in self.results[suit]:
              self.results[suit][face] = 1
            else:
              self.results[suit][face] += 1

        for suit, faces in self.results.items():
              for face, count in faces.items():
                  if count < self.__percent_low or self.__percent_high < count:
                      print(face + " of " + suit + " : " + str(count) + '\n',
                              file=sys.stderr)
                      sys.exit(2)


    def __Exec(self, target, str_in=None):
        """Method documentation goes here.
        """
        with subprocess.Popen([target], stderr=subprocess.PIPE,
                stdin=subprocess.PIPE, stdout=subprocess.PIPE) as proc:
          out, err = proc.communicate(input=str_in)
          
          try:
            return proc.returncode, out.decode("utf-8") if out else None
          except UnicodeDecodeError as e:
            return proc.returncode, "Serious execution badness:" + format(e)


    def __str__(self):
        val = str()
        for suit in self.results:
            for face, count in sorted(self.results[suit].items()):
                val += "{} of {} : {}\n".format(face, suit, count)

        return val


if __name__ == "__main__":
    test = QuickTest(50000)
    print(test)
    sys.exit(0)
