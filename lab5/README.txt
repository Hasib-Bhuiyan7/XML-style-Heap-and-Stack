The code works fine.

Question:
1.) 
It would require a simple modification on Requirement 1 to allow this type of tag; in the code for part 1, the file is parsed through, looking for '<' and '\'to indicate tags. Using just an additional if-statement placed right after when the code parses through and obtains the XML ID, this conditional statement can check for '/' and the ending '>'. If it does find it, the code does not push it to the stack as it is 'self-balancing' and just moves through it. 