# Merge Sort Walkthrough

Given array:

`[38, 27, 43, 3, 9, 82, 10]`

## Step 1: Divide the Array

Merge sort repeatedly divides the array into two halves until each subarray has only one element.

```text
         [38, 27, 43, 3, 9, 82, 10]
        /                          \
   [38, 27, 43]                 [3, 9, 82, 10]
     /        \                 /         \
 [38]      [27, 43]         [3, 9]      [82, 10]
            /     \           /   \       /   \
          [27]    [43]      [3]   [9]   [82]  [10]
```

## Step 2: Merge and Sort

Now merge the subarrays back together in sorted order.

### Merge 1

`[27] + [43] -> [27, 43]`

### Merge 2

`[38] + [27, 43]`

Comparisons:

- `27 < 38` -> `[27]`
- `38 < 43` -> `[27, 38]`
- Remaining element: `43` -> `[27, 38, 43]`

Left side becomes:

`[27, 38, 43]`

---

### Merge 3

`[3] + [9] -> [3, 9]`

### Merge 4

`[82] + [10]`

Comparisons:

- `10 < 82` -> `[10, 82]`

### Merge 5

`[3, 9] + [10, 82] -> [3, 9, 10, 82]`

Right side becomes:

`[3, 9, 10, 82]`

---

## Final Merge

`[27, 38, 43] + [3, 9, 10, 82]`

Compare elements step by step:

- `3` -> `[3]`
- `9` -> `[3, 9]`
- `10` -> `[3, 9, 10]`
- `27` -> `[3, 9, 10, 27]`
- `38` -> `[3, 9, 10, 27, 38]`
- `43` -> `[3, 9, 10, 27, 38, 43]`
- `82` -> `[3, 9, 10, 27, 38, 43, 82]`

Sorted array:

`[3, 9, 10, 27, 38, 43, 82]`

## Summary

`Divide -> Divide -> Divide -> Merge -> Merge -> Sorted Array`
