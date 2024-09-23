-- Quicksort for Assignment 1

quicksort :: Ord a => [a] -> [a]
quicksort [] = []
quicksort (x:xs) = 
    let small = quicksort [a | a <- xs, a <= x]
        big = quicksort [a | a <- xs, a > x]
    in  small ++ [x] ++ big

main :: IO ()
main = do

    -- let test1 = []   -- Will Crash
    -- putStrLn "Test 1 (Empty List)"
    -- print $ quicksort test1
    
    let test2 = [5, 4, 3, 2, 1]
    putStrLn "\nTest 2"
    print $ quicksort test2
    
    let test3 = [4, 2, 4, 1, 3, 2]
    putStrLn "\nTest 3"
    print $ quicksort test3
    
    -- let test4 = [4, A, 4, C, 3, 2]   -- Will Crash
    -- putStrLn "\nTest 4 (Empty List)"
    -- print $ quicksort test4
