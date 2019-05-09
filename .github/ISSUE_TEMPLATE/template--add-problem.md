---
name: 'Template: Add Problem'
about: Add an issue for the CTCI problems to be completed
title: "[TOPIC]: Write-up for question [#]"
labels: backlog
assignees: ''

---

Procedure for completing a problem & solution writeup for UWB ACM CTCI sessions:

- [ ] Assign an issue to yourself
- [ ] Pick a problem to write up. Please check the prior quarter's session to ensure we don't have duplicates between quarters. Some good places to look are [LeetCode](https://leetcode.com/), [HackerRank](https://www.hackerrank.com/), and of course [CTCI](http://www.crackingthecodinginterview.com). Communicate with your colleagues to ensure we have good topic coverage and nobody is writing up duplicate questions.
- [ ] Clone this repository to your computer, if you haven't already. If you have, `cd` into the repo's directory, run `git checkout master`, and run `git pull origin master`.
- [ ] Run `git checkout -b <my-topic-name>`, and name the branch something logical. (Pick a short name for the problem you are writing up, for example.)
- [ ] `cd` into the directory with the solutions file for the session. The naming conventions should make the file's location fairly self-evident.
- [ ] Add the problem description in the appropriate numbered selection in the solutions file.
- [ ] Add the solution writeup in the appropriate numbered selection in the solutions file.
- [ ] Add a driver program (which includes your solution) in a subdirectory that produces the output included in the solutions file.
- [ ] Run `git commit`. Add a useful commit description, so that reviewers know what they're looking at.
- [ ] Run `git push origin <my-topic-name>`, using the branch name you chose earlier.
- [ ] Navigate to [the GitHub repository](https://github.com/UWB-ACM/CTCI) and open a Pull Request for your submitted branch.
- [ ] Request a review from one or more designated PR reviewers for the session.
- [ ] If your reviewer requests changes, please address all suggestions.

As always, if you experience issues or have questions, talk to your peers. We are here to help each other!
