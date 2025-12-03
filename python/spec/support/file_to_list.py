#!/usr/bin/env python3
#

def file_to_list(filename):
  lyst = []

  with open(filename, 'r') as file:
    for lyne in file:
      lyne = lyne.strip()
      if len(lyne):
        lyst.append(lyne)

  return lyst

