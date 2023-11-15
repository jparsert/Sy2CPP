; default grammar added
(set-logic BV)
(synth-fun inv((x (_ BitVec 32))(d (_ BitVec 32)))
 Bool
(( NTbool Bool)(NTnonbool (_ BitVec 32)))
((NTbool Bool((and NTbool NTbool)(or NTbool NTbool)(not NTbool)(= NTnonbool NTnonbool)(bvuge NTnonbool NTnonbool)(bvugt NTnonbool NTnonbool)))
(NTnonbool (_ BitVec 32)(x d (_ bv0 32) (_ bv1 32) (_ bv2 32) (_ bv3 32)  (bvadd NTnonbool NTnonbool)(bvsub NTnonbool NTnonbool)(bvshl NTnonbool NTnonbool)(bvlshr NTnonbool NTnonbool)(bvurem NTnonbool NTnonbool)(ite NTbool NTnonbool NTnonbool)))

)
)

(declare-var c1 Bool)
(declare-var c2 Bool)
(declare-var d (_ BitVec 32))
(declare-var d1 (_ BitVec 32))
(declare-var d2 (_ BitVec 32))
(declare-var s (_ BitVec 32))
(declare-var x (_ BitVec 32))
(declare-var x1 (_ BitVec 32))
( constraint  (=> (and (and (and (and (= d (_ bv1 32)) (=> c1 (= d1 (bvsub d (_ bv1 32))))) (=> (not c1) (= d1 d))) (=> c2 (= d2 (bvsub d1 (_ bv1 32))))) (=> (not c2) (= d2 d1))) (inv x d2 )) ) 
( constraint  (=> (and (and (inv x d ) (bvugt x (_ bv0 32))) (= x1 (bvsub x d))) (inv x1 d )) ) 
( constraint  (=> (and (inv x d ) (bvule x (_ bv0 32))) (bvule x (_ bv0 32))) ) 
(check-synth)
