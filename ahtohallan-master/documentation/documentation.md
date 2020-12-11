[Home Page](../README.md)

<!-- vim-markdown-toc GFM -->

* [Google Chrome](#google-chrome)
* [Mozilla Firefox](#mozilla-firefox)
* [Offline](#offline)
	* [Install Sight](#install-sight)
		* [Customize Sight](#customize-sight)
	* [Install Markdown Viewer](#install-markdown-viewer)
		* [Customize Markdown Viewer](#customize-markdown-viewer)
	* [Clone the Repsoitory (Linux)](#clone-the-repsoitory-linux)
		* [Update the Repository (Linux)](#update-the-repository-linux)
	* [Clone the Repository (Windows)](#clone-the-repository-windows)
		* [Update the Repository (Windows)](#update-the-repository-windows)
* [Mobile](#mobile)

<!-- vim-markdown-toc -->

----

# Google Chrome
If you are on Google Chrome, follow these steps to open the code files automatically on **Github**.

* Add the [Redirector Extension](https://chrome.google.com/webstore/detail/redirector/ocgpenflpmgnfapjedencafcfakcekcd/related?hl=en)
* Click on the `Redirector` icon from the *Toolbar* and select `Edit Redirects`.
* Click on `Create new redirect`
* Add the **description** as `GH-Pages to Github`.
* Add the **example-url** as [this-url](https://just-a-visitor.github.io/sugar-rush/bny-mellon/set-1/sequence-sum/sequence-sum-solution.cpp) . (**Tip** : Right click and select `copy-link-address`).
* Add the **include-pattern** as `https://just-a-visitor.github.io/sugar-rush/*.cpp`  
* Add the **redirect-to** to `https://github.com/Just-A-Visitor/sugar-rush/blob/master/$1.cpp`
* Select **pattern-type** as `wildcard`.
* Include the **pattern-description** as `Redirects all the code on GH Pages to the corresponding Github repo`.
* Click on **Save**.
* Go to `chrome://extensions` and select the newly added extension's **Details**.
* Click on `allow in incognito mode` if you are using a guest session.
* Restart Chrome if needed.
* Now, when you open a code file on **GH-Pages**, you should be automatically redirected to **Github**. You can use browser-buttons to navigate back.
 

----

# Mozilla Firefox
To be updated!

----

# Offline
If you don't have a good internet connnectivity or if you'd like to retain a local copy of the repository, follow these steps.

## Install Sight
* Install the [sight extension](https://chrome.google.com/webstore/detail/sight/epmaefhielclhlnmjofcdapbeepkmggh)
* Go to `chrome://extensions` and select the newly added extension's `Details`.
* Enable the `allow access to file URLs`.
* Click on `allow in incognito mode` if you are using a guest session.
* Restart Chrome if needed.

### Customize Sight
* Click on the **Sight** icon from the toolbar, and select `options`.
* Choose your theme (I'd suggest you try out `Darkula`).
* Select your preferred font. 
* Select the font size (`Medium` should work fine I guess).
* Choose whether you want to enable `line numberings`.



## Install Markdown Viewer
* Install the [markdown extension](https://chrome.google.com/webstore/detail/markdown-viewer/ckkdlimhmcjmikdlpkmbgfkaikojcbjk) to view these files in your browser.
* Go to `chrome://extensions` and select the newly added extension's **Details**.
* Enable the `allow access to file URLs`.
* Click on `allow in incognito mode` if you are using a guest session.
* Restart Chrome if needed.
* You can customize it to hide **TOC** (as I already include one).

### Customize Markdown Viewer


## Clone the Repsoitory (Linux)
Open up a terminal and type

```bash
git clone https://github.com/Just-A-Visitor/sugar-rush.git
cd sugar-rush
google-chrome README.md
```

This should open the homepage of the repository in your browser. You can navigate easily now (provided you've added **Sight** and **Markdown Viewer**).

### Update the Repository (Linux)
To update your local copy of the repo, open a terminal and type

```bash
cd sugar-rush
git pull
```

## Clone the Repository (Windows)
If you are viewing this on the website, click on download `.zip` file. Extract it to your desired directory. Finally, open the `README.md` file with Google Chrome. Now, you can navigate easily, assuming you have already added **Sight** and **Markdown Viewer**.

### Update the Repository (Windows)
If you aren't familiar with Git, you'll have to manually update your clone each time.

----

# Mobile
If you are on mobile, you can view the contents without any issue. However, you wont' be able to read the codes. To enable that feature, you'd have to browse the repository in **Github** (which you can easily do so by clicking `View Project on Github`).

----
