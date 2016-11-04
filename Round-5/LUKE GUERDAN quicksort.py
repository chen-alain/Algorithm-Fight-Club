def quicksortRecur(array, low, high):
   print "Entering quicksort: " + str(array) + "   low: %d - high: %d" % (low, high)

   if (low > high):
      return

   pivot = array[(low + high) / 2]
   print "pivot: %d\n" % pivot
   i = low
   j = high

   while(i <= j):
      while(array[i] < pivot):
         i += 1

      while(array[j] > pivot):
         j = j - 1

      if(i <= j):
         temp = array[i]
         array[i] = array[j]
         array[j] = temp
      i += 1
      j = j - 1

   if (low < j):
      quicksortRecur(array, 0, pivot - 1)

   if (high > i):
      quicksortRecur(array, pivot, high)


def quicksortIter1(array, low, high):
   print "Entering quicksort: " + str(array) + "   low: %d - high: %d" % (low, high)

   if (low > high):
      return

   pivot = array[(low + high) / 2]
   print "pivot: %d\n" % pivot
   i = low
   j = high

   while(i <= j):
      while(array[i] < pivot):
         i += 1

      while(array[j] > pivot):
         j = j - 1

      print "about to comare: array[i] = %d  array[j] = %d" % (array[i], array[j])
      if(i <= j):
         temp = array[i]
         array[i] = array[j]
         array[j] = temp
      i += 1
      j = j - 1

   return
   if (low < j):
      quicksortIter1(array, 0, pivot - 1)

   if (high > i):
      quicksortIter1(array, pivot, high)



array = [8, 5, 9, 3,2,1, 1, 7]
quicksortRecur(array, 0, len(array) - 1)
quicksortIter1(array, 0, len(array) - 1)

print array
