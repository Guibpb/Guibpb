(defun imc (peso altura)
    (let* 
        ((total (/ peso (expt altura 2)))
        (result
            (cond
                ((< total 20) "muito magro")
                ((< total 25) "normal")
                ((< total 30) "obesidade grau 1")
                ((< total 35) "obesidade grau 2")
                (t "obesidade grau 3")   
            )
        ))
        (list total result)
    )
)