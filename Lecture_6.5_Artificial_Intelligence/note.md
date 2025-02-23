# Lecture 6.5
## Image Generation
## ChatGPT
* text generation tool
## Prompt Generation
* Prompt generation is the way by which an individual can communicate with an AI platform.
## Generative AI
## Decision Trees
* Decision trees are used by an algorithm to decide what decision to make.
```
While game is ongoing:
If ball is left of paddle:
  Move paddle left
Else if ball is right of padding:
  Move paddle right
Else:
  Don't move paddle
```
* Why AI is good at games?
  * inputs and outputs that can be represented mathematically
  * a goal in the form of a function to maximize/minimize(以函数形式最大化/最小化目标)
## Minimax(极小极大算法)
* In tic-tac-toe(井字游戏), the AI may consider a board where the computer wins as 1 and one where the computer loses as -1.
* The computer will attempt to win by maximizing its own score.
```
If player is X:
For each possible move:
  Calculate score for board
Choose move with highest score

Else if player is O:
  For each possible move:
    Calculate score for board
  Choose move with lowest score
```
![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_6.5_Artificial_Intelligence/images/image.png?raw=true)
## Machine Learning
* Machine learning is a way by which a computer can learn through reinforcement(强化)(奖励正确的行为，惩罚错误的行为).
* The computer repeats trial(试验) after trial after trial to discover what behaviors to repeat and those not to repeat.
* Within much of AI-based algorithms, there are concepts of explore vs. exploit(开拓), where the AI may randomly try something that may not be considered optimal(最佳的). Randomness can yield better outcomes(随机性可以产生更好的结果).
## Deep Learning
* Deep learning uses neural networks whereby problems and solutions are explored.(深度学习使用神经网络来探索问题和解决方案)
* For example, deep learning may attempt to predict whether a blue or red dot will appear somewhere on a graph.
  ![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_6.5_Artificial_Intelligence/images/image-1.png?raw=true)
* Existing training data is used to predict an outcome.
* Deep learning creates nodes (pictured below), which associate inputs and outputs.
  ![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_6.5_Artificial_Intelligence/images/image-2.png?raw=true)
## Generative Artificial Intelligence(生成式人工智能)
* Large language models are massive models that make predictions based on huge amounts of training.
* The AI encodes words into embeddings to find relationships between words. Thus, through a huge amount of training, a massive neural network can predict the association between words - resulting in the ability for generative AI to generate content and even have conversations with users.
