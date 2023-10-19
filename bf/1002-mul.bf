 ++++[>++++[>+++<-]<-]		# initialize cell2 to 'O'
    ,>,>                    	# store the data read into cell0 and cell1
    [<-<->>-]               	# reduce the value of cell0 and cell1 by 'O'
    <<                      	# return to cell0
    [                       	# do the multiplication
        >                   	# go to cell1
        [>+>+<<-]           	# move cell1 to both cell2, cell3
        >>                  	# now go to cell3
        [<<+>>-]            	# move cell3 cell1
        <<<-                	# reduce the value of cell0
    ]
    >[-]<                   	# now set the value of cell1 (use as counter)
    ++++[>++++[>+++<-]<-]   	# to get the result at cell2 add '0' to it
    >>.				# Move the memory pointer two cells to the right & print the char @ current memory cell
