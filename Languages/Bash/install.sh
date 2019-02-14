declare -a programName=(
    "geogebra" 
    "build-essentials"
    "nethogs"
    "python3"
)

totalPrograms=${#programName[@]}

declare -a programSelect=(
    true
    true
    true
    true
)

# Get arguments for dialog box
declare -a dialogArgs
for ((i=0; i<$totalPrograms; i++))
    do
        dialogArgs[$i]="$i ${programName[$i]}"
        if ${programSelect[$i]}
        then
            dialogArgs[$i]+=" on"
        else
            dialogArgs[$i]+=" off"
        fi
    done

# Create dialog box and save settings to temp file
dialog --title "Installer" --checklist "Select programs to install" 20 40 15 ${dialogArgs[@]} 2> options.tmp
printf "\n"

# Parse temp file and update options
printf "[Configuration]\n"
for ((i=0; i<$totalPrograms; i++))
    do
        status=false
        while read -n1 char
            do
                if [ "$char" == $i ]
                then
                    status=true
                    break
                fi
            done < options.tmp
        programSelect[$i]=$status
        printf "%-20s\t%s\n" ${programName[$i]} ${programSelect[$i]}
    done
printf "\n"
rm options.tmp

# Install files
printf "[Installing]\n"
for ((i=0; i<$totalPrograms; i++))
    do
        if ${programSelect[i]}
        then
            printf ">> Installing %s\n" ${programName[$i]} 
            sudo apt-get install "$program"
            printf "\n"
        else
            printf ">> Skipping %s\n" ${programName[$i]}
        fi
    done
