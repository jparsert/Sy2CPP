; default grammar added
(set-logic BV)
(synth-fun f_141-11-141-28((x.end (_ BitVec 32))(size (_ BitVec 32))(i (_ BitVec 32))(elem.end (_ BitVec 32)))
 Bool
(( NTbool Bool)(NTnonbool (_ BitVec 32)))
((NTbool Bool((and NTbool NTbool)(or NTbool NTbool)(not NTbool)(= NTnonbool NTnonbool)(bvuge NTnonbool NTnonbool)(bvugt NTnonbool NTnonbool)))
(NTnonbool (_ BitVec 32)(x.end size i elem.end (_ bv0 32) (_ bv1 32) (_ bv2 32) (_ bv3 32)  (bvadd NTnonbool NTnonbool)(bvsub NTnonbool NTnonbool)(bvshl NTnonbool NTnonbool)(bvlshr NTnonbool NTnonbool)(bvurem NTnonbool NTnonbool)(ite NTbool NTnonbool NTnonbool)))

)
)

(declare-var elem.end_141-11-141-28 (_ BitVec 32))
(declare-var i_141-11-141-28 (_ BitVec 32))
(declare-var size_141-11-141-28 (_ BitVec 32))
(declare-var x.end_141-11-141-28 (_ BitVec 32))
( constraint  (=> (and (= size_141-11-141-28 (_ bv3 32)) (and (= x.end_141-11-141-28 (_ bv122 32)) (and (= elem.end_141-11-141-28 (_ bv110 32)) (= i_141-11-141-28 (_ bv2 32))))) (= (f_141-11-141-28 x.end_141-11-141-28 size_141-11-141-28 i_141-11-141-28 elem.end_141-11-141-28 ) true)) ) 
( constraint  (or (=> (and (= size_141-11-141-28 (_ bv2 32)) (and (= x.end_141-11-141-28 (_ bv15 32)) (and (= elem.end_141-11-141-28 (_ bv15 32)) (= i_141-11-141-28 (_ bv1 32))))) (= (f_141-11-141-28 x.end_141-11-141-28 size_141-11-141-28 i_141-11-141-28 elem.end_141-11-141-28 ) false)) (=> (and (= size_141-11-141-28 (_ bv2 32)) (and (= x.end_141-11-141-28 (_ bv15 32)) (and (= elem.end_141-11-141-28 (_ bv15 32)) (= i_141-11-141-28 (_ bv1 32))))) (= (f_141-11-141-28 x.end_141-11-141-28 size_141-11-141-28 i_141-11-141-28 elem.end_141-11-141-28 ) true))) ) 
( constraint  (=> (and (= size_141-11-141-28 (_ bv3 32)) (and (= x.end_141-11-141-28 (_ bv122 32)) (and (= elem.end_141-11-141-28 (_ bv110 32)) (= i_141-11-141-28 (_ bv2 32))))) (= (f_141-11-141-28 x.end_141-11-141-28 size_141-11-141-28 i_141-11-141-28 elem.end_141-11-141-28 ) true)) ) 
( constraint  (=> (and (= size_141-11-141-28 (_ bv3 32)) (and (= x.end_141-11-141-28 (_ bv122 32)) (and (= elem.end_141-11-141-28 (_ bv111 32)) (= i_141-11-141-28 (_ bv2 32))))) (= (f_141-11-141-28 x.end_141-11-141-28 size_141-11-141-28 i_141-11-141-28 elem.end_141-11-141-28 ) true)) ) 
( constraint  (=> (and (= size_141-11-141-28 (_ bv2 32)) (and (= x.end_141-11-141-28 (_ bv3 32)) (and (= elem.end_141-11-141-28 (_ bv4 32)) (= i_141-11-141-28 (_ bv1 32))))) (= (f_141-11-141-28 x.end_141-11-141-28 size_141-11-141-28 i_141-11-141-28 elem.end_141-11-141-28 ) false)) ) 
( constraint  (=> (and (= size_141-11-141-28 (_ bv2 32)) (and (= x.end_141-11-141-28 (_ bv122 32)) (and (= elem.end_141-11-141-28 (_ bv109 32)) (= i_141-11-141-28 (_ bv1 32))))) (= (f_141-11-141-28 x.end_141-11-141-28 size_141-11-141-28 i_141-11-141-28 elem.end_141-11-141-28 ) true)) ) 
( constraint  (=> (and (= size_141-11-141-28 (_ bv2 32)) (and (= x.end_141-11-141-28 (_ bv300 32)) (and (= elem.end_141-11-141-28 (_ bv305 32)) (= i_141-11-141-28 (_ bv1 32))))) (= (f_141-11-141-28 x.end_141-11-141-28 size_141-11-141-28 i_141-11-141-28 elem.end_141-11-141-28 ) false)) ) 
( constraint  (=> (and (= size_141-11-141-28 (_ bv2 32)) (and (= x.end_141-11-141-28 (_ bv2 32)) (and (= elem.end_141-11-141-28 (_ bv21 32)) (= i_141-11-141-28 (_ bv1 32))))) (= (f_141-11-141-28 x.end_141-11-141-28 size_141-11-141-28 i_141-11-141-28 elem.end_141-11-141-28 ) false)) ) 
(check-synth)
