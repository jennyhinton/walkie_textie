# Walkie Textie
## GitHub Instructions

### **Starting Out**
1. Install Git on your computer
    - Git may already be installed. If you go into a terminal and type 'git' and a bunch of help text appears, then you are good to go.
    - Otherwise, install Git from this link: https://git-scm.com/downloads

2. Setup SSH Keys
    - Follow the steps in this link to make your life a lot easier: https://docs.github.com/en/github/authenticating-to-github/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent


3. Cloning the repository to your machine
    - Open a terminal and navigate to the folder you want the project files to be stored.
    - Run this command: 
    ```
    git clone git@github.com:jennyhinton/walkie_textie.git
    ```
    - After this you should have a folder named *walkie_textie* that you can navigate into.
4. Now we want to fetch all of the *remote* branches from the repository and set up your local branch. If you run `git remote -v` and you should see that there is one remote named **origin** that links to the walkie_textie repository. Run the following commands:
    ```
    git fetch origin
    git branch [name] origin/dev
    git checkout [name]
    ```
5. You are now on a local copy of your designated branch. Changes to this branch will not affect the shared repository until you commit and push your changes.

### **Updating your local branch**
1. Before you make any changes to your local branch, you should make sure your local branch is updated with the **origin/dev** branch.
    - **origin/dev** is the branch that will hold all of the combined changes everybody in the group makes. Keeping your branch up to date with origin/dev will make sure you are working on the latest code.
    - To update your branch, make sure you are on your designated branch and all of your changes are **pushed** (we will talk about pushing later) and then run the following command:
    ```
    git pull origin dev
    ```
    - There may be merge conflicts when you run this command, if this happens then you just need to figure out how to resolve the conflicts. Talk to group members about this and use online resources.

2. You are now good to work on the code

### **Pushing your changes**
1. After you have made some changes to the code and want to store these changes in the repository, you want to **push** your changes.

2. You can start by running `git status` to see all the files you have made changes to.

3. Next, you can prepare your changes for a commit by running the following command(s). `git add .` or `git add *`
    - The dot adds all the files in the current directory, while the star adds all files. You should be fine to run either command.
    - You can run `git status` again after adding your changes and you should see the files in a green color.

4. After adding your changes you need to commit them. Committing a change adds a unique ID to the changes so that if you can revert back to the time before the changes were made if need be. You also add a VERY IMPORTANT commit message with the commit so everybody knows what the changes were for. This can be done using the following command:
```
git commit -m "Descriptive message goes here"
```

5. Now you can finally push your changes to the shared repository. For this project you will only need to push to your **[name]** branch.
```
git push origin [name]
```

6. Together, all of these commands will look like this:
```
git status
git add .
git commit -m "Description message"
git push origin [name]
```
7. Your changes should now be reflected in the shared repository.

### **Creating a pull request**
1. Once you are at a point where the team wants to pull together everybody's changes and make sure everything works together you will want to submit a pull request into **origin/dev**.

2. After pushing all of your changes to your **[name]** branch, go to the shared repository and change the active branch from **main** to **[name]**

3. Press the *Pull Request* tab and then click the green *New pull request* button. 

4. Change the **base:** branch to be **base: dev**

5. Change the **compare:** branch to be **compare: [name]**.

6. Review the changes that show up and then create the pull request using the green button.

7. The pull request should now be created and the team can look at it together and merge it into **origin/dev** if everything looks good.




