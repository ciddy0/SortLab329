-- define the merge function
merge :: Ord a=> [a] -> [a] -> [a]
-- merging a empty list with any list will return the list
merge [] xs = xs
merge xs [] = xs

-- piece-wise function in order sort the list
merge (x:xs) (y:ys)
    -- if x<= y then add it to the taill of the first list (xs)
    | x <= y    = x : merge xs (y:ys)
    -- else add y to the result of mergng the entire first list (x:xs)
    | otherwise = y : merge (x:xs) ys

-- define the mergeSort function
mergeSort :: Ord a => [a] -> [a]

-- base case empty list
mergeSort [] = []
-- other base case for when a list has one element
mergeSort [x] = [x]

-- mergeSort on xs and recursively call mergeSort
mergeSort xs = merge (mergeSort left) (mergeSort right)
    -- local binding that splits the list in half
    where
        (left, right) = splitAt (length xs `div` 2) xs

main :: IO()
main = do
   -- case for sorting numbers
   let list = [9,3,5,1,2,4,10,8,7,6]
   let sortedList = mergeSort list
   putStrLn ("unsorted: " ++ show list)
   putStrLn ("sorted: " ++ show sortedList)
   
   -- case for empty list
   -- have to set the empty list to any type or ghc will throw an error
   let list1 :: [Int]
       list1 = []
   let sortedList1 = mergeSort list1
   putStrLn ("unsorted: " ++ show list1)
   putStrLn ("sorted: " ++ show sortedList1)
   
   -- case to sort chars
   let charList = ['c','i','d']
   let sortedCharList = mergeSort charList
   putStrLn ("unsorted: " ++ show charList)
   putStrLn ("sorted: " ++ show sortedCharList)
   

