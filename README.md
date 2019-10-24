
<h1 class="title">Programming Assignment 3</h1>
<h2>HTML Validator</h2>
</header>
<h2 id="this-assignment-tests-the-concepts-of">This assignment tests the concepts of</h2>
<ul>
<li>Linked list</li>
<li>Stacks</li>
<li>Queues</li>
</ul>
<h2 id="background">Background</h2>
<p>A markup language is a system for inserting annotations into a document. The most important feature of a markup language is that the tags it uses to indicate annotations should be easy to distinguish from the document content.</p>
<p>One of the most well-known markup languages is the one commonly used to create Web pages, called HTML, or “Hypertext Markup Language”. In HTML, tags appear in “angle brackets” such as in “&lt;html&gt;”. When you load a Web page in your browser, you don’t see the tags themselves: the browser interprets the tags as instructions on how to format the text for display.</p>
<p>Most tags in HTML are used in pairs to indicate where an effect starts and ends. For example:</p>
<ul>
<li>&lt;p&gt; represents the start of a paragraph, and &lt;/p&gt; indicates where that paragraph ends.</li>
<li>&lt;b&gt; and &lt;/b&gt; are used to place the enclosed text in bold font, and &lt;i&gt; and &lt;/i&gt; indicate that the enclosed text is italic.</li>
</ul>
<p>Note that “end” tags look just like the “start” tags, except for the addition of a slash after the &lt; symbol.</p>
<p>Sets of tags are often nested inside other sets of tags. For example, an ordered list is a list of numbered bullets. You specify the start of an ordered list with the tag &lt;ol&gt;, and the end with &lt;/ol&gt;. Within the ordered list, you identify items to be numbered with the tags &lt;li&gt; (for “list item”) and &lt;/li&gt;. For example, the following specification:</p>
<div class="sourceCode" id="cb1"><pre class="sourceCode html"><code class="sourceCode html"><a class="sourceLine" id="cb1-1" title="1"><span class="kw">&lt;ol&gt;</span></a>
<a class="sourceLine" id="cb1-2" title="2">  <span class="kw">&lt;li&gt;</span>First item<span class="kw">&lt;/li&gt;</span></a>
<a class="sourceLine" id="cb1-3" title="3">  <span class="kw">&lt;li&gt;</span>Second item<span class="kw">&lt;/li&gt;</span></a>
<a class="sourceLine" id="cb1-4" title="4">  <span class="kw">&lt;li&gt;</span>Third item<span class="kw">&lt;/li&gt;</span></a>
<a class="sourceLine" id="cb1-5" title="5"><span class="kw">&lt;/ol&gt;</span></a></code></pre></div>
<p>would result in the following:</p>
<pre><code>1. First item 
2. Second item  
3. Third item</code></pre>
<p>Notice how you start the ordered list with the &lt;ol&gt; tag, specify three line items with matching &lt;li&gt; and &lt;/li&gt; tags, and the close the ordered list with the &lt;/ol&gt; tag.</p>
<p>You may have noticed that the pattern of using matching tags strongly resembles the pattern of matching parentheses that we discussed in class: when you use parentheses, brackets, and braces, they have to match in reverse order, such as “{[()]}”. A pattern such as “[(])” would be incorrect since the right bracket does not match the left parenthesis. Similarly, an HTML pattern such as &lt;ol&gt;&lt;li&gt;&lt;/ol&gt;&lt;/li&gt; would be incorrect since the closing tags are in the wrong order.</p>
<h2 id="program-objective">Program Objective</h2>
<p>You will write a “HTML Checker” program that takes as input an HTML file, and produces a report indicating whether or not the tags are correctly matched.</p>
<ul>
<li>Just as the parenthesis checker uses a stack to store symbols waiting for a match to be found, your program should also use a stack. You will also need to implement a stack class (you will ignore the fact that the STL has one).</li>
<li>The HTML file name should be expected to be passed as a command line argument. See previous lab for example.</li>
<li>The first task your program must do is read in an HTML file and extract the tags. The htmltags class attemps to simply this by automatically creating a queue of tags.</li>
</ul>
<p>In addition, have your program build a list of all seen tags. As you iterate through your list of tags, check to see if the tag appears in the list. If it doesn’t, add it to the list and print the message, “New tag XXX found and added to list of valid tags”. The list should be kept in alphabetical order.</p>
<p>Input:</p>
<p>Provided four example files. Some contain errors, some do not.</p>
<p>Output:</p>
<p>The output of your program should include the following:</p>
<ul>
<li>A printout of your list of tags (the result of your repeated calls to getTag).</li>
<li>One line for each tag as you process it, explaining the action and showing the current contents of the stack. Some examples are:
<ul>
<li>Tag b pushed</li>
<li>Tag /b matches top of stack</li>
<li>Tag ul pushed</li>
<li>A message every time you add a tag to VALIDTAGS.</li>
</ul></li>
</ul>
<p>Your program should end with either: Processing complete. Invalid HTML5. Tag is XXX but top of stack is YYY or Processing complete. Document is valid. Unique tags seen in sorted order: !doctype a body div head html img li link meta or Processing complete. Invalid HTML5. Tags matched, however, [center,font] are not a valid HTML5 tag(s) Unique tags seen in sorted order: !doctype a body div head html img li link meta or Processing complete. Invalid HTML5. Unmatched tags remain on stack: [XXX, YYY, ZZZ]</p>
<h2 id="other-requirements">Other Requirements</h2>
<ul>
<li>Execution will be tested via the existence of the above wording.</li>
<li>The tags must be placed in a stack and used to verify validity</li>
<li>For full credit your code should have zero compiler warnings.</li>
<li>Your code will be checked for memory leaks. Memory leaks will be verified via a tool called “valgrind” as well as visually.</li>
<li>Usage of any STL containers other than list will affect grade detrimentally.</li>
<li>Avoid all STL items except std::copy (algorithm), std::swap (algorithm or utility), assert (cassert), size_t. In addition, you may use functions from the following libraries: iostream.</li>
<li>Usage of recursion will result in no credit</li>
<li>Only submit the file(s) listed in deliverables, submitting object files, IDE project files, and executables will impact grade.</li>
<li>Don’t forget to document the queue and stack class, see course outline for details. See the FIXME in the class documenation.</li>
</ul>
<h2 id="attachments">Attachments</h2>
<p>stack should only contain the following methods, they should all be public:</p>
<div class="sourceCode" id="cb3"><pre class="sourceCode c++"><code class="sourceCode cpp"><a class="sourceLine" id="cb3-1" title="1">stack();</a>
<a class="sourceLine" id="cb3-2" title="2"><span class="dt">void</span> pop();</a>
<a class="sourceLine" id="cb3-3" title="3"><span class="at">const</span> T&amp; top() <span class="at">const</span>;</a>
<a class="sourceLine" id="cb3-4" title="4">T&amp; top();</a>
<a class="sourceLine" id="cb3-5" title="5"><span class="dt">void</span> push(<span class="at">const</span> T&amp;);</a>
<a class="sourceLine" id="cb3-6" title="6"><span class="dt">bool</span> empty() <span class="at">const</span>;</a>
<a class="sourceLine" id="cb3-7" title="7"><span class="dt">void</span> clear();</a></code></pre></div>
<p>queue should only contain the following methods, they should all be public:</p>
<div class="sourceCode" id="cb4"><pre class="sourceCode c++"><code class="sourceCode cpp"><a class="sourceLine" id="cb4-1" title="1">queue();</a>
<a class="sourceLine" id="cb4-2" title="2"><span class="dt">void</span> dequeue();</a>
<a class="sourceLine" id="cb4-3" title="3"><span class="at">const</span> T&amp; front() <span class="at">const</span>;</a>
<a class="sourceLine" id="cb4-4" title="4">T&amp; front();</a>
<a class="sourceLine" id="cb4-5" title="5"><span class="dt">void</span> enqueue(<span class="at">const</span> T&amp;);</a>
<a class="sourceLine" id="cb4-6" title="6"><span class="dt">bool</span> empty() <span class="at">const</span>;</a>
<a class="sourceLine" id="cb4-7" title="7"><span class="dt">void</span> clear();</a></code></pre></div>
