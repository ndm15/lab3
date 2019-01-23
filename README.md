# Lab 3

This lab is about tools. You will learn to do a tiny bit of Git from the
command line, to navigate directories, and to configure pipenv the
actually easy way (once you know how).

## Navigating in the command line

Whether you are using Windows or Mac, it’s really helpful to be able to
do a few things on the command line. And to understand it, one of the
most important concepts is the *current working directory*. This is sort
of like “where you are” on your computer when you type a command.

For example, you might be in your home directory (`/Users/YOURNAME` on
Mac, or maybe `C:\Users\YOURNAME`), which means that when you type a
filename, it means a file in that directory (unless you give its full
name, starting with `/` or `C:\`). And when you run a command like Git
or pipenv, it looks in your current directory for what files to work
with as well.

So, you need to be able to:

  - Know how directory names are written.

  - Know what directory you are in.

  - Know what is in your directory.

  - Know how to change directories.

### Writing paths

You are probably already familiar with the concept of directories, also
known as folders. They form a hierarchical structure, and when you want
to write down their names, you are writing a path through the structure,
with each segment separated by the directory separator character: `/` on
Mac, or `\` on Windows.

So, `foo/bar/baz` (or `foo\bar\baz` on Windows)  means the file or
directory `baz` which is inside directory `bar`, which is inside
directory `foo`. Where is `foo`, though? Relative to your current
working directory! (If you write `/foo/bar/baz` on Mac, or
`C:\foo\bar\baz` on Windows, those are absolute paths relative to the
root of the disk, not relative to your current working directory.)

Note that when writing paths (directory and filenames) in a command, you
sometimes need to use quotation marks or backslashes if the path
contains special characters, including spaces. Suppose you have a file
named “my file” that you want to delete. This won’t work:

```
Mac$ rm my file
Win> del my file
```

because in both cases, it sees `my` and `file` as separate words,
and looks for two different files with those names. But this works:

```
Mac$ rm my\ file
Win> del my\ file
```

### Knowing where you are

Chances are, your current working directory is in your prompt already,
but you can also print it:

```
Mac$ pwd
Win> echo %cd%
```

### Listing directory contents

To see what’s there:

```
Mac$ ls
Win> dir
```

You can also see what is someplace else. The special name `..` means the

list that includes the directory you are currently in:

```
Mac$ ls ..
Win> dir ..
```

### Changing directories

If you are in your home directory (`C:\Users\YOU` or `/Users/YOU`), you
probably have, say, a Desktop subdirectory there (or maybe it has some
other name). You can change into it like so:

```
Mac$ cd Desktop
Win> cd Desktop
```

Like other commands, the argument to `cd` is interpreted relative to
where you are, unless you give an absolute path. So to get back home,
you could do:

```
Mac$ cd ..
Win> cd ..
```

On Mac, you can actually get back home easily from wherever you are,
like this:

```
Mac$ cd
```

I suggest you play around, moving around your computer and seeing what
you can see. Where are programs stored? Where are documents stored?

## Git from the command line

There is one git command I want you to know:

```
Mac$ git clone SOME_REPO_URL
Win> git clone SOME_REPO_URL
```

That fetches the contents of `SOME_REPO_URL` and creates a new
subdirectory within the current directory to store it. The name of the
new directory will be the name of the repo. For example, if you git
clone `https://github.com/eecs230/lab3` then you will get a new
directory named `lab3`. What if you want to name it something different?
`git clone` can take an additional parameter, the target:

```
Mac$ git clone SOME_REPO_URL my_new_directory
Win> git clone SOME_REPO_URL my_new_directory
```

(One problem you may have when running this command, especially on
Windows, is that the `git` command may not be in your “path.” The path
is a list of directories that your computer searches for commands
whenever you type one. If you installed Git during lab1, but when you
try to run it, you get an error message that it doesn’t exist, that is
probably why. So you might have to go looking, and ask your TA for help.
Here’s a place to start: `C:\Program Files (x86)\Git\bin`.)

So, clone this lab, because the next step will involve navigating inside
it and setting it up:

```
Mac$ git clone https://github.com/eecs230/lab3
Win> git clone https://github.com/eecs230/lab3
```

## Setting up pipenv from the command line

Now, change into your new lab3 directory, and check out what's there:

```
Mac$ cd lab3
Mac$ ls

Win> cd lab3
Win> dir
```

If you've done it right you should see these files:

 - Pipfile
 - README.md
 - lab3.py
 - pytest.ini

The next step is going to be to run pipenv to set things up. The tricky
part is finding pipenv. And to do that, we’re going to ask Python. You
all seem to have slightly different python setups, so I'm just going to
refer to the Python interpreter as `$PY`. That might mean one of these:

 - `py` (Windows)
 - `python3` (Mac?)
 - `python3.7` (Windows?)
 - `python37` (Mac)
 - `C:\Python37\python.exe` (definitely Windows)
 - `python`

Whatever it's called, check and make sure it's the right version, and


```
Mac$ $PY --version
Win> $PY --version
```

Now, from within the `lab3` directory, run this (replacing `$PY` with
your Python):

```
Mac$ $PY -m pipenv install --dev
Win> $PY -m pipenv install --dev
```

It will take a few moments, but when it's done, your Python environment
should be good to go, without a bunch of complaints from PyCharm. Once
it’s ready, check that it's good to go by running pytest:

```
Mac$ $PY -m pipenv run pytest
Win> $PY -m pipenv run pytest
```

You should see one test passed.

Now, try opening the current directory in PyCharm:

```
Mac$ open -a PyCharm .
Win> pycharm .
```

(Not sure if that Windows command will work. It depends on whether
`PyCharm.exe` is on your path... But you all know how to start PyCharm,
anyway.)

## Git remotes

If you cloned your `lab3` directory from
`https://github.com/eecs230/lab3`, that means that your local copy of
the repo has a *remote* set to point there, which is what tells `pull`
(downloading) and `push` (uploading) where to go. That remote is named
`origin`, but you can have additional remotes with additional names,
which lets you upload to and download from any of them, as you please.

This would let you, for example, have your own copy of lab3 (or
eecs230/code) that you can push your changes to, while still being able
to pull my future changes from the original. Cool, right?

So let's set that up for lab3:

  1. Go to [the lab](https://github.com/eecs230/lab3) on GitHub and fork
     it to your own account.

  2. In PyCharm, add a second remote. Go to *VCS* > *Git* > *Remotes…*.
     You should see your one remote, `origin`, pointing to where you
     cloned from. Add another remote pointing to your fork. (Maybe name
     it `my_fork`?)

  3. Make a change to `lab3.py`, and commit (*VCS* > *Commit…*), but
     don’t push yet. (You can't push to `origin`, anyway.)

  4. Now open the Push dialog (*VCS* > *Git* > *Push*), but before you
     click the “Push” button, you want to change the destination remote
     from `origin` to your new remote (`my_fork`?). At the top, you
     should see something like ``master -> origin : master.'' Clicking
     `origin` will let you change it to your other remote. Then push.

  5. Now here’s the fun part: Your TA is going to make a change to
     https://github.com/eecs230/lab3, and you are going to retrieve that
     change and merge it in. (Tell your TA to make the change, in case
     they haven’t noticed this part. I suggest that they add a file
     rather than editing the same file you edited, since if you both
     edit the file in the same place then it can't merge your changes
     automatically.)

 6. After your TA pushes the change, you want to do a pull from your
    `origin` remote to your local copy. Go to *VCS* > *Git* > *Pull…*.
    Before you click the “Pull” button, make sure that the remote is set
    (back) to `origin`. (Pulling from your fork won't do anything, since
    you're currently in synch with your fork.) Complete the pull, and
    you should now have both the changes you made and the changes your
    TA made in one place.

Now you can push back to your fork, and it will contain the merged
changes. The workflow going forward is you pull from `origin` to get
your TA’s (or my) changes, and push to your fork to save your changes
there.
