#!/usr/bin/env python3
#

class GiftShop:

    def __init__(self, ranges=list()):
        self.ranges = [item.split('-') for item in ranges[0].split(',')]
        pass

    def mirrored(self):
        accumulator = 0
        for (lo, hi) in self.ranges:
            if len(lo) == len(hi):
                accumulator += self.__mirror(lo, hi)
            elif len(lo) < len(hi):
                accumulator += \
                    self.__mirror(lo, "9" * len(lo)) + self.__mirror("1" + "0" * len(lo), hi)
            else:
                0

        return(accumulator)

    def __mirror(self, lo, hi):
        if len(lo) % 2:
            return 0
        if len(hi) % 2:
            return 0

        magnitude = int(10 ** (len(lo) / 2))
        lo = int(lo)
        hi = int(hi)

        lo_upper, lo_lower = int(lo / magnitude), int(lo % magnitude)
        hi_upper, hi_lower = int(hi / magnitude), int(hi % magnitude)

        if lo_lower < lo_upper:         #   84 promotes to 88
            lo_lower = lo_upper
        elif lo_lower == lo_upper:      #   66 remains
            pass
        else:                           #   48 promotes to 55
            lo_upper += 1
            lo_lower = lo_upper

        lo = (lo_upper * magnitude) + lo_lower
        hi = (hi_upper * magnitude) + hi_lower

        if lo <= hi:
            accumulator = 0
            magnitude += 1
            for item in range(lo, 1+hi, magnitude):
                accumulator += item

            return(accumulator)
        else:
            return(0)

    def repeated(self):
        accumulator = 0
        for (lo, hi) in self.ranges:
            if len(lo) == len(hi):
                accumulator += self.__repeat(lo, hi)
            elif len(lo) < len(hi):
                accumulator += \
                    self.__repeat(lo, "9" * len(lo)) + self.__repeat("1" + "0" * len(lo), hi)
            else:
                0

        return(accumulator)

    def __repeat(self, lo, hi):
        magnitude = len(lo)
        accumulator = set()

        for digits in range(1, 1+int(magnitude/2)):
            if not (magnitude % digits):
                scale = int(magnitude / digits)
                starter = int(f"{lo[0:digits]}" * (scale))
                increment = int(f"{'0'*(digits-1) + '1'}" * (scale))
                localized = self.__repetition(starter, int(lo), int(hi), increment)
                accumulator.update(localized)

        return sum(accumulator)

    def __repetition(self, starter, lower, upper, increment):
        localized = set()

        while (starter < lower):
            starter += increment

        for spam in range(starter, 1+upper, increment):
            localized.add(spam)

        return localized

