(setf lis '(a b c))

(cond
  ((and (evenp (length lis))
        (numberp (car lis))
        (numberp (second lis)))
   (setf newlis (list (car lis) (second lis)))
   (setf lis (cddr lis)))

  ((numberp (car lis))
   (setf newlis (list (car lis)))
   (setf lis (cdr lis)))

  (t
   (setf lis (cdr lis))
   (setf newlis nil))
)
