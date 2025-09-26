alias pscheck='f(){ 
  min=1
  max=""
  for arg in "$@"; do
    case $arg in
      -min=*) min="${arg#*=}" ;;
      -max=*) max="${arg#*=}" ;;
      *) n="$arg" ;;
    esac
  done
  if [ -z "$max" ]; then
    max=${n:-100}
  fi
  ARG=$(python3 -c "import random,sys; a=list(range($min, $max+1)); random.shuffle(a); print(\" \".join(map(str,a)))")
  echo \"$ARG\"
  ./push_swap $ARG | ./checker_Mac $ARG
}; f'
alias psarg='f(){ ARG="$@"; echo "$ARG"; ./push_swap $ARG | ./checker_Mac $ARG; }; f'
alias git-push='git add * && git commit -m "update" && git push'
alias psleak='f(){ARG="$@"; echo "$ARG"; valgrind --leak-check=full --show-leak-kinds=all ./push_swap $ARG | ./checker_Mac $ARG; }; f'
