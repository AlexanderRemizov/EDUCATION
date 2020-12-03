<ol>
For this course, you need to be using a Unix shell like Bash or ZSH. If you
are on Linux or macOS, you don’t have to do anything special. If you are on
Windows, you need to make sure you are not running cmd.exe or PowerShell;
you can use <a href="https://docs.microsoft.com/en-us/windows/wsl/">Windows Subsystem for
Linux</a> or a Linux virtual
machine to use Unix-style command-line tools. To make sure you’re running
an appropriate shell, you can try the command <code class="language-plaintext highlighter-rouge">echo $SHELL</code>. If it says
something like <code class="language-plaintext highlighter-rouge">/bin/bash</code> or <code class="language-plaintext highlighter-rouge">/usr/bin/zsh</code>, that means you’re running the
right program.</li>
  <li>Create a new directory called <code class="language-plaintext highlighter-rouge">missing</code> under <code class="language-plaintext highlighter-rouge">/tmp</code>.</li>
  <li>Look up the <code class="language-plaintext highlighter-rouge">touch</code> program. The <code class="language-plaintext highlighter-rouge">man</code> program is your friend.</li>
  <li>Use <code class="language-plaintext highlighter-rouge">touch</code> to create a new file called <code class="language-plaintext highlighter-rouge">semester</code> in <code class="language-plaintext highlighter-rouge">missing</code>.</li>
  <li>Write the following into that file, one line at a time:
    <div class="language-plaintext highlighter-rouge"><div class="highlight"><pre class="highlight"><code>#!/bin/sh
curl --head --silent https://missing.csail.mit.edu
</code></pre></div>    </div>
    <p>The first line might be tricky to get working. It’s helpful to know that
<code class="language-plaintext highlighter-rouge">#</code> starts a comment in Bash, and <code class="language-plaintext highlighter-rouge">!</code> has a special meaning even within
double-quoted (<code class="language-plaintext highlighter-rouge">"</code>) strings. Bash treats single-quoted strings (<code class="language-plaintext highlighter-rouge">'</code>)
differently: they will do the trick in this case. See the Bash
<a href="https://www.gnu.org/software/bash/manual/html_node/Quoting.html">quoting</a>
manual page for more information.</p>
  </li>
  <li>Try to execute the file, i.e. type the path to the script (<code class="language-plaintext highlighter-rouge">./semester</code>)
into your shell and press enter. Understand why it doesn’t work by
consulting the output of <code class="language-plaintext highlighter-rouge">ls</code> (hint: look at the permission bits of the
file).</li>
  <li>Run the command by explicitly starting the <code class="language-plaintext highlighter-rouge">sh</code> interpreter, and giving it
the file <code class="language-plaintext highlighter-rouge">semester</code> as the first argument, i.e. <code class="language-plaintext highlighter-rouge">sh semester</code>. Why does
this work, while <code class="language-plaintext highlighter-rouge">./semester</code> didn’t?</li>
  <li>Look up the <code class="language-plaintext highlighter-rouge">chmod</code> program (e.g. use <code class="language-plaintext highlighter-rouge">man chmod</code>).</li>
  <li>Use <code class="language-plaintext highlighter-rouge">chmod</code> to make it possible to run the command <code class="language-plaintext highlighter-rouge">./semester</code> rather than
having to type <code class="language-plaintext highlighter-rouge">sh semester</code>. How does your shell know that the file is
supposed to be interpreted using <code class="language-plaintext highlighter-rouge">sh</code>? See this page on the
<a href="https://en.wikipedia.org/wiki/Shebang_(Unix)">shebang</a> line for more
information.</li>
  <li>Use <code class="language-plaintext highlighter-rouge">|</code> and <code class="language-plaintext highlighter-rouge">&gt;</code> to write the “last modified” date output by
<code class="language-plaintext highlighter-rouge">semester</code> into a file called <code class="language-plaintext highlighter-rouge">last-modified.txt</code> in your home
directory.</li>
  <li>Write a command that reads out your laptop battery’s power level or your
desktop machine’s CPU temperature from <code class="language-plaintext highlighter-rouge">/sys</code>. Note: if you’re a macOS
    user, your OS doesn’t have sysfs, so you can skip this exercise. </ol>

## Solution

```bash
# 1
AMBS:shell DOUBLEU$ mkdir missing
# 2
AMBS:shell DOUBLEU$ man touch
# 3
AMBS:shell DOUBLEU$ cd missing
AMBS:missing DOUBLEU$ touch semester
# 4
AMBS:missing DOUBLEU$ nano semester 
# 5
AMBS:missing DOUBLEU$ ./semester
# 6 
AMBS:missing DOUBLEU$ sh semester
# 7 
AMBS:missing DOUBLEU$ man chmod
# 8
AMBS:missing DOUBLEU$ chmod +x semester
AMBS:missing DOUBLEU$ ./semester
# 9
AMBS:missing DOUBLEU$ date -r semester > last-modified.txt 
# 10 I have Mac
```

