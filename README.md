Bjolt
=====

Bjolt is a filter for Bjam (aka Boost Build) that makes it look prettier in Windows. Lines with errors turn red, warnings turn yellow, and long running lines are formatted to make them easier to read.

**Before:**

<img src="http://250968154fb4b7e5c40f-b1f678667098b568846f17aaeca5bb41.r13.cf2.rackcdn.com/BjoltBefore.png"/>

**After:**

<img src="http://250968154fb4b7e5c40f-b1f678667098b568846f17aaeca5bb41.r13.cf2.rackcdn.com/BjoltAfter.png"/>


### Building ###

Building Solace requires <a href="http://border-town.com/macaroni/">Macaroni</a>
 and <a href="http://www.boost.org/doc/libs/1_54_0/more/getting_started/windows.html">Boost Build</a>.

Assuming both are configured, all that's needed to build from source is to execute "macaroni build".

Alternatively, simply <a href="http://250968154fb4b7e5c40f-b1f678667098b568846f17aaeca5bb41.r13.cf2.rackcdn.com/bjolt.exe">download it</a>. You may need to also install <a href="http://www.microsoft.com/en-us/download/details.aspx?id=40784">the Visual C++ Redistributable Packages for Visual Studio 2013</a>.

### Installing ###

1. Copy "bjolt.exe" to the same directory where "bjam.exe" resides.

2. Rename "bjam.exe" to "bjam-old.exe". You'll need to keep this file around.

3. Rename "bjolt.exe" to "bjam.exe".

