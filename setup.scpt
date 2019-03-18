tell application "iTerm2"
    tell current window
        create tab with profile "Default"
    end tell

    tell current session of current window
        split horizontally with default profile
        write text “cd /Users/chandan.p/Documents/Chandan/Chandan-Git && source .env && source bin/activate" 
        split vertically with default profile
    end tell
end tell
