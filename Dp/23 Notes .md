# 🎯 Target Sum Formula Comparison

## 🔴 LeetCode Assumes:

```
sum(P) - sum(N) = target
```

where **P** means all positive numbers and **N** means all negative numbers

```
sum(P) = (target + sum(N)) → which is (totalSum + target) / 2
```

### ✅ Final Formula in LeetCode:

```
subsetSum = (totalSum + target) / 2
```

---

## 🔵 Coding Ninja Assumes:

```
sum(P) + sum(N) = target
```

```
sum(P) = target - sum(N) → (totalSum - target) / 2
```

### ✅ Final Formula in Coding Ninja:

```
subsetSum = (totalSum - target) / 2
```