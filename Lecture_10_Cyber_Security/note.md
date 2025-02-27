# Lecture 10
## Tools
* [wsl](https://learn.microsoft.com/en-us/windows/wsl/about)
* [git](https://www.youtube.com/watch?v=MJUJ4wbFm_A)
* [vscode](https://cs50.readthedocs.io/cs50.dev/)
* You can host a web app using [AWS](https://aws.amazon.com/cn/education/awseducate/), [Azure](https://azure.microsoft.com/en-us/free/students/), or [Google Cloud](https://cloud.google.com/edu/students).
* You can ask questions using AI-based tools like [OpenAI](https://chatgpt.com/) and [GitHub Copilot](https://github.com/features/copilot).
## Cybersecurity
* Cybersecurity is understanding how our data is secure or not secure.
## Passwords
* Passwords are one method used to secure data online.
## Phone Security
```python
from string import ascii_letters, digits, punctuation
from itertools import product

# ascii_letters: a-z A-Z
# digits: 0-9
# punctuation: 特殊符号
for passcode in product(ascii_letters + digits + punctuation, repeat=8):
    print(passcode)
```
## Password Managers
* Password managers can be used to create very challenging passwords and remember them for you.
## Two-factor Authentication(双因素身份验证)
* Adding another means by which you must authenticate adds further security. 
## Hashing
* One-way hashing(单向哈希) allows online services to actually never store the original password typed by the user: Only the hashed value of these passwords. Accordingly, if there is a breach(违规), only the hashed value will be known.
* Rainbow tables are huge dictionaries that adversaries(敌人) use to attempt to pre-hash possible passwords as a means by which to attempt to break the hash algorithm.
* As an additional process to heightened security, programmers may sometimes introduce salting where it becomes unlikely that multiple users may have the same hash value to represent their passwords.
## Cryptography(密码学)
* Similar to hashing, a cipher(加密) algorithm can use a public key(公钥) and text to create ciphertext(密文).
* In turn, a private key and the ciphertext can be fed to the algorithm to decrypt(解密) the text.
* 非对称加密：public key可以告知给任何人，其他人使用public key对原始文件进行加密，发送出去，接收方使用private key解密
## Passkeys
* Through private keys and a challenge being fed to an algorithm, websites can authenticate you through the unique signature created by your device.
![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_10_Cyber_Security/images/image.png?raw=true)
* website保存用户的public key，向用户发送challenge信息，用户使用private key对challenge进行加密，发送给website，website使用public key可还原challenge，认为该用户可授权。
## Encryption(加密)
* End-to-end encryption(端到端加密) is a way by which encrypting and decrypting happen on the same system without a middleman. This prevents the middleman or a malicious actor from being able to snoop(窥探) on your data. 
## Deletion
* Trashing a file on your computer or emptying the trash can does not actually delete the actual bits of the file on your computer. Instead, remnants(残余部分) of the files are left.
* Secure deletion is where the remnants of those files are turned into zeros and ones.
* Still, some remnants may remain because of what is rendered inaccessible by the operating system.
* Full-disk encryption allows your entire hard drive to be encrypted. Thus, your deleted files are less accessible to adversaries.(windows上的bitlocker对硬盘进行加密，即使硬盘被拿走，不知道密码也无法破解)
## git
* git status
* git log
* git branch
* git add <file>
* git commit -m <"message">
* git branch <new-branch-name>
* git checkout <branch-name>
* git switch <branch-name>
* git push
* git fetch
* git diff master origin/master
* git pull