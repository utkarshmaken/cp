The best way to learn is by debugging your incorrect solution. However, it's not always trivial to do so, as the numbers in the test-cases might be too large, making it impossible to dry-run the test case or even analyse it. Moreover, the positioning of the test-cases also matter, (as was the case with the first-test case of **Diamond Mine**). You'd have no idea how your solution performs on the other test-cases if it fails the first test-case for some reason (which is not exactly a bad thing, but can be frustrating sometimes).

To overcome this, I have decided to provide the generators and the test-script for all the problems so that you can debug it locally on smaller test-cases (with minimal effort).

It might take some time to setup, but once you're done, you'd be up and running within 3 minutes. I'd strongly advise you to go through this article.

With that said, you need to draw the line somewhere and decide when to give up. But whatever you do, you should atleast know why your solution was wrong, even if you don't correct it.

----

<!-- vim-markdown-toc GFM -->

* [Tips](#tips)
* [Clone the repo and pull the latest changes](#clone-the-repo-and-pull-the-latest-changes)
* [Prepare the script and the incorrect solution](#prepare-the-script-and-the-incorrect-solution)
* [Customize the generator](#customize-the-generator)
* [Run the tests](#run-the-tests)
* [Tech Support](#tech-support)
* [Credits](#credits)

<!-- vim-markdown-toc -->

----

# Tips
1. To copy any of the terminal commands from this article, triple click anywhere on the line.
2. For auto-completion in terminal, type a prefix and press `<tab>`.
3. To open the current directory in *File Explorer*, type `nautilus .`

----

# Clone the repo and pull the latest changes
Open up a terminal (`Ctrl + Alt + T`) and type : 

```sh
git clone git@github.com:Just-A-Visitor/sugar-rush.git
cd ~/sugar-rush
git pull
```

**Note** : If you've already cloned the repostiory before, you won't need the first command.

Open up the **File Explorer** and navigate to the relevant contest folder.

This is a typical directory structure.
```sh
sugar-rush
└── mathworks
    └── set-1
        ├── diamond-mine-hard
        │   ├── diamond-mine-hard.md
        │   ├── gen-all-ones.cpp
        │   ├── gen-all-zeroes.cpp
        │   ├── gen.cpp
        │   ├── gen-diagonal-minus.cpp
        │   ├── gen-extreme.cpp
        │   ├── gen-extreme-no-thorns.cpp
        │   ├── gen-man-greedy-dp.txt
        │   ├── gen-man-leetcode.txt
        │   ├── gen-no-thorns.cpp
        │   ├── gen-small.cpp
        │   └── solution.cpp
        └── mathworks-set-1.md
```

* Normally, you'd find only 2 generators, `gen.cpp` and `gen-extreme.cpp`
* However, at times, I might include other corner-case generators (as you can see in the above image).
* Generators which include the full test-case (rather than the code) are prefixed with `gen-man`.
* The model solution is present in the file called `solution.cpp`. 

----

# Prepare the script and the incorrect solution

First, copy the script presents at `~/sugar-rush/documentation/stress.sh` to the relevant problem folder. You can do this via a File Explorer. If you are using a terminal, type

```sh
cd ~/sugar-rush/company-name/set-num/prob-name/
cp ~/sugar-rush/documentation/stress.sh stress.sh
```

Now, create a file called `stupid.cpp`

```sh
touch stupid.cpp
```

Open the file in your favourite text-editor and paste your solution. For example, if you are using `gedit`, you can type.

```sh
gedit stupid.cpp
```

This would open up the file. Now you can paste your solution.

If you prefer a different editor, you can open the file explorer for the current directory by typing

```sh
nautilus .
```

----

# Customize the generator
Since the default generator would produce uniformly generated random numbers, you need to lower the limits for the tests to be readable. Open the `gen.cpp` file in your favourite text editor. For Gedit, type : 

```sh
gedit gen.cpp
```
At the top of the file, you might see something like :

```cpp
/********************* Custom Inputs ***************************/

const int n_low = 1;
const int n_high = 2*(int)(1e5);

/********************* Custom Inputs ***************************/
```

Change the lower limits and upper limits as you desire and save the file.

----

# Run the tests
Make sure that you are in the correct directory.

```sh
cd ~/sugar-rush/company-name/set-num/prob-name/
```

1. Make the script executable.

```sh
chmod +x stress.sh
```

**Note** : You only need to do this step **once** per problem.

2. Run the script

```sh
./stress.sh
```

You should see something like

```sh
OK + 1
OK + 2
...
```

If your solution is wrong, at some point, it would terminate with the message

```
Found Failing Test
```

To terminate the process manually, type `Ctrl + C`.


* The input for which it failed would be present inside the file called `in`.
* The expected output would be present inside the file called `out`.
* The incorrect output would be present inside the file called `out-stupid`.

You can view these files in gedit using

```sh
gedit file_name
```

or by using other editors through the file explorer

```sh
nautilus .
```

At this point, you should make modifications to your program. Once you are done, switch to the terminal and type.

```sh
g++ stupid.cpp && ./a.out < in > out-stupid
cmp --silent out out-stupid || echo "Incorrect Solution"
```

If the screen is blank after the execution, it means your solution passes this test case. To run the script again for further debugging, run

```sh
./stress.sh
```

**Rinse and Repeat** till you spot the error (or give up!).

----

# Tech Support
If you see a weird error message, or get stuck somewhere, raise an [issue](https://github.com/Just-A-Visitor/sugar-rush/issues). Although I can't guarantee a fast response, I'd try to get it resolved within a day or so.

----

# Credits
* [Website](http://www.algos.school/stress-testing)
* [Video](https://www.youtube.com/watch?v=JXTVOyQpSGM)

----
