# MarkdownParser  

Noxy/MarkdownParser: v0.1.0 beta  

## Description  

The aim of this Markdown Parser is to translate a .md file in a .html file via c++, where the result .html can be loaded by a browser.  
Therefore that there are diffrent styling Guides for Markdown-Syntax, it is to recommend to look up (below)[] for the syntax this Markdown Parser is using.  

## Step-By-Step Coding plan  


## Reading Description

- [ ] Iterate over line and read content
    - [ ] Detect if line contains special char 
    - _If_ '#' at line[0] make a headline
    - _Else If_ line starts with whitespaces
        - Remember position [n]
        - Read lines until whitespaces are closed
        - Wrap everything in <tags>
        - _IF_ line contains double as much whitspaces as the line before
            - Read again
    - _Else If_ line has special char
        - Remember position [n]
        - Read until special char closes
        - Wrap everything in <tags>
        - remove special char [n] and [n+1]
    - Read again from [n]

## Special Char Definition

To follow Definitions, first it is written an '-' than a whitespaces and everything between the following "\ CONTENT  \" (Backslash + whitespaceContent + Backslash), is for what the Parser will check.  

### Headings

- \\# CONTENT  \         = <h1></h1>
- \\## CONTENT  \        = <h2></h2>
- \\### CONTENT  \       = <h3></h3>
- \\#### CONTENT  \      = <h4></h4>
- \\##### CONTENT  \     = <h5></h5>
- \\###### CONTENT  \    = <h6></h6>

### Bold  
- \\**CONTENT**\         = <strong>CONTENT</strong>  

### Italic  
- \\_CONTENT_\           = <i>CONTENT</i>  

### Mixed Italic + Bold  
- \\**_CONTENT_**\       = <strong><i>CONTENT</i></strong>  

### Linebreaks
- \\CONTENT  \           = CONTENT</br>  

### LINKS
