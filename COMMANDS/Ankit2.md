# Git Workflow Commands

This document contains all the Git commands needed to complete the feature branch development and hotfix branch management tasks.

## Problem 1: Feature Branch Development Workflow

### Create branches
```bash
git branch main               
git branch login-feature
```

### Work on login-feature
```bash
git checkout login-feature
echo "Login Module: Initial implementation" > login.txt
git add login.txt
git commit -m "LoginFeatureCommit"
```

### Modify file on main branch
```bash
git checkout main
echo "Login Module: Main branch implementation" > login.txt
git add login.txt
git commit -m "MainLoginCommit"
```

### Merge Branch
```bash
git merge login-feature
```

If conflict occurs, resolve by editing login.txt to contain:
```
Login Module: Initial implementation
Login Module: Main branch implementation
```

Then commit:
```bash
git add login.txt
git commit -m "LoginMergeResolved"
```

## Problem 2: Hotfix Branch Management

### Initialize Git
```bash
cd /home/ubuntu/code/project
git init
```

### Create Branches
```bash
git branch main
git branch hotfix
```

### Make Changes in Both Branches

Switch to main:
```bash
git checkout main
echo "Main branch hotfix update" > hotfix.txt
git add hotfix.txt
git commit -m "MainHotfixCommit"
```

Switch to hotfix:
```bash
git checkout hotfix
echo "Hotfix branch update" > hotfix.txt
git add hotfix.txt
git commit -m "HotfixCommit"
```

### Merge and Resolve Conflict
```bash
git checkout main
git merge hotfix
```

Resolve conflict by editing hotfix.txt to contain:
```
Main branch hotfix update
Hotfix branch update
```

Then commit:
```bash
git add hotfix.txt
git commit -m "HotfixConflictResolved"
```
