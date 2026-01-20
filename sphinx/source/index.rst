.. Advent of Code 2025, Polyglot Edition documentation master file, created by
   sphinx-quickstart on Mon Dec 29 23:29:12 2025.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

#####################################
Advent of Code 2025, Polyglot Edition
#####################################

Advent of Code
is an n-week exercise in the ``map`` and ``reduce`` list operations;
every challenge *reduces* a *transformed* list of text down to one numeric value.
There may be other filtering intervals along the way, but the answer to each
day's part is one and only one number. That makes testing easy, for the sample
data sets come with correct values, and we arrive at the submitted values
by switching the incoming data set. And that's how I'll prove the code, by
running tests of each method on both the *sample* and *actual* data.

Each method operates on that list of input. Gathering the input is the purview
of and only of testing, so the test harness shall have embedded within it a
``file_to_list`` function that reads from a file and returns a list of that
file's non-empty lines (of text). And that function has its own test.

Tests express two contexts,
against the *Sample* data and against the *Actual* data

Sample data tests assert that both *Part 1* and *Part 2* challenges
agree with the given answers.

Actual data tests no-op the result of each challenge (actual answer above),
and then assert that those values haven't changed (results survive).

This year, I'll attack each day's challenge in five different languages:

#. ruby
#. python
#. go
#. elixir
#. c
#. *cobol*

My past Advents were only in ruby, so its object-oriented paradigm shined.
I was trivially able to preserve that model with python, but when I got to go,
and then even moreso elixir, with less and no emphasis on objects and classes,
respectively, then I started thinking about data over objects.

Go and elixir express the (tight) relationship between data and operations
on it through structure types and module namespaces.

Taking the first day's ``SecretEntrance`` as a guide,
the ruby and python codes each define a ``class`` that gets
initialized with the list of text.

.. code-block:: ruby
   :linenos:
   :caption: SecretEntrance in Ruby

   module Aoc2025
      class SecretEntrance
         def initialize turns=[]
            @turns = ...
         end
      end
   end

.. code-block:: python3
   :linenos:
   :caption: SecretEntrance in Python3

   class SecretEntrance
      def __init__(self, turns=list()):
         self.turns = ...


In go, I define a ``struct`` as a list of (immutable) integers.
and a ``NewSecretEntrance``
function that transforms the list of text into the list of numbers.

.. code-block:: go
   :linenos:
   :caption: SecretEntrance in Go

   type SecretEntrance struct {
      Turns []int
   }

   func NewSecretEntrance(turns []string) *SecretEntrance {
      me := &SecretEntrance {
         Turns: make([]int, 0)
      }
      ...
      me
   }

Elixir expresses like ruby but as a nested ``module`` vice a ``class`` and no
``self.`` methods within. I do not know what the convention is for constructing
an appropriate data structure, so we'll go with the small-snake-case version
of the UpperCamelCase chapter/module name.

.. code-block:: elixir
   :linenos:
   :caption: SecretEntrance in Elixir

   defmodule Aoc2025.SecretEntrance do
      def secret_entrance data do
         Enum.map(data, fn(lyne) ->
            ...
         end)
      end
   end

I confess I like/appreciate the statelessness of the elixir approach,
maybe because fresh.

C is portable assembly, so you gotta do everything.
I won't package it up with poudriere (or rpm or deb or whatever).
I *will* shoehorn in the ``file_to_list`` idiom, where the ``list_t`` payload
is unionized against whatever each challenge requires; naming will be fun.

.. code-block:: c
   :linenos:
   :caption: SecretEntrance in C; Generic list payload

   typedef struct list_s {
      union {
         struct {
            char *text;
            size_t strlen;
         } str;
         long long int z;
         size_t nn[2];
      } u;

      struct list_s *next;
   } list_t;

The *constructor* will take in a ``list_t *`` chain with the ``.u.str``
populated, and will return an ``aoc_t`` structure that contains a ``list_t *``
chain that's possibly/likely been processed, and addresses to the ``part1`` and
``part2`` reductions.

.. code-block:: c
   :linenos:
   :caption: SecretEntrance in C; An object of sorts

   typedef struct aoc_s {
      size_t (*part1)(const list_t *data);
      size_t (*part2)(const list_t *data);
      const list_t *data;
   } aoc_t;

Any processing shall be carried out by the same constructor function that
assigns the function addresses.
By my own convention, let's call it ``transform``.
We'll follow the same-case convention for naming the *constructor* function.

.. code-block:: c
   :linenos:
   :caption: SecretEntrance in C; A constructor of sorts

   aoc_t *
   secret_entrance(list_t *data) {
      aoc_t me = {
         .part1 = zeroes,
         .part2 = clicks,
         .data = transform(data)
      };

      return memdup((void *) &me, sizeof(me));
   }

... where the private/static ``transform`` function molests the lines of text
into whatever's appropriate for that challenge, as well as the values
for the parts.
(The ``memdup()`` here is a my more literal ``strdup(1)`` utility.)

Over in ``bdd-for-c``-ville, where the ``part1`` and ``part2`` get called,
I must also give those calls the (processed) data, because only C.

.. code-block:: c
   :linenos:
   :caption: SecretEntrance in C; Calling Part 1

   aoc_t *subject = secret_entrance(file_to_list("day_01_sample.txt"));

   subject->part1(subject->data);

One last thing: all functions internal to each challenge would normally be
``static`` scoped, but I'll need to test them, and ``bdd-for-c`` can only
work on symbols it can see, so the ``static`` is commented-out.

This is probably overkill a bit, but I like never having to think about
the innards of ``file_to_list`` ever again, that an incoming list is formed
to that module, and every code common to each challenge is templated.


.. keep toc-tree near the bottom so non-html expressions preserve content order

.. toctree::
   :maxdepth: 2
   :numbered:
   :caption: Day by Day:

   secret_entrance
   gift_shop


Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`
